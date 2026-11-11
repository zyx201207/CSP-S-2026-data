#include<iostream>
using namespace std;
//A B C   D F
//0 1 2   3 5

bool checkce(char Ca,char Cb){
	int a=Ca-'A',b=Cb-'A';
	if(a<=2 && b<=2)return 1;
	if(a>=3 && b>=3)return 1;
	return 0;
}

bool checkling(char Ca,char Cb){
	int a=Ca-'A',b=Cb-'A';
	if(a-b==1||b-a==1)return 1;
	if(a==3 && b==5 || a==5 && b==3)return 1;
	return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cx,cr,px,pr;
	char sx,sr;
	
	cx=(getchar()-'0')*10+getchar()-'0';
	getchar();
	px=(getchar()-'0')*10+getchar()-'0';
	sx=getchar();

    getchar();

	cr=(getchar()-'0')*10+getchar()-'0';
	getchar();
	pr=(getchar()-'0')*10+getchar()-'0';
	sr=getchar();
	getchar();

	bool cb=(cx==cr);
	bool pb=(cb && px==pr);
	bool ceb=(pb && checkce(sx,sr));
	bool lingb=(ceb && checkling(sx,sr));
	cout<<cb<<pb<<ceb<<lingb<<"\n";
}