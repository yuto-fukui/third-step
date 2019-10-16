#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float ave(float*);//平均値計算
float hyoujyun(float*,float);//標準偏差の計算
void hensati(float*,float*,float,float);//偏差値の計算
//float dispersion(float*,float);
float sum(float*);//合計点の計算
int compare(const void *,const void*);//qsort用比較関数


int main(){
	float english[20] ={65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70};
        float science[20]={44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84};
	float hensati_eng[20];
	float hensati_sci[20];

	float ave_eng,ave_sci;
	float dev_eng,dev_sci;
	float sum_eng,sum_sci;
	float dis_eng,dis_sci;

	int i;
        //平均値の計算
	ave_eng = ave(english);
	ave_sci = ave(science);

	//標準偏差の計算
	dev_eng = hyoujyun(english,ave_eng);
	dev_sci = hyoujyun(science,ave_sci);

	//合計点の計算
	sum_eng = sum(english);
	sum_sci = sum(science);

	//偏差値の計算
	hensati(english,hensati_eng,ave_eng,dev_eng);
	hensati(science,hensati_sci,ave_sci,dev_sci);

	//並び替え
	qsort(english,sizeof(english)/sizeof(float),sizeof(float),compare);
	qsort(science,sizeof(science)/sizeof(float),sizeof(float),compare);

	//結果の表示
	printf("ave_eng : %f\n",ave_eng);
	printf("ave_science: %f\n",ave_sci);

	printf("standard deviation_eng : %f\n",dev_eng);
	printf("standard_deviation_science: %f\n",dev_sci);

	printf("sum_eng : %f\n",sum_eng);
	printf("sum_science: %f\n",sum_sci);

	printf("hensati_eng :[ ");
	for(i = 0; i < 20;i++){
	  printf(" %.1f ,",hensati_eng[i]);
	}
	printf("]\n");

	printf("hensati_science :[ ");
	for(i = 0; i < 20;i++){
	  printf(" %.1f ,",hensati_sci[i]);
	}
	printf("]\n");

	printf("sort_eng :[");
	for(i = 0; i < 20;i++){
	  printf(" %.1f ,",english[i]);
	}
	printf("]\n");

	printf("sort_science :[");
	for(i = 0; i < 20;i++){
	  printf(" %.1f ,",science[i]);
	}
	printf("]\n");


}

float sum(float* point){
	int i;
	float sum=0;
	for(i=0;i<20;i++){
		sum = sum + *(point + i);
	}
	return sum;
}

float ave(float *point){
	int i;
	float sum=0,ave=0;

	for(i = 0;i<20;i++){
		sum = sum + *(point + i);
		
		//printf("sum:%f\n",sum );
	}

	ave = sum/20;

	return ave;
}
float dipersion(float*point,float ave){
	int i;
	float dev;
	float sum = 0;

	for(i=0;i<20;i++){
		sum = sum + (*(point + i) - ave) * (*(point + i) - ave);
	}

	sum = sum/20.0;
        return sum;
}

float hyoujyun(float*point,float ave){
	int i;
	float dev;
	float sum=0;

	for(i=0;i<20;i++){
		sum = sum + (*(point + i) - ave) * (*(point + i) - ave);
	}

	sum = sum/20.0;
	dev = sqrt(sum);

	return dev;
}

void hensati(float*point,float*result, float ave,float dev){
       int i;
       
       for(i = 0;i<20;i++){
	       *(result+i) = (*(point+i) - ave)/dev * 10 + 50;
       }

}

int compare(const void* a,const void* b){
	float* A = (float*)a;
	float* B = (float*)b;
	if(*A-*B >0){
		return -1;
	}
	else if(*A-*B == 0){
		return 0;
	}
	else
		return 1;
}

	



