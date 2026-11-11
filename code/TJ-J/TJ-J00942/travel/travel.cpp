#include<cstdio>
#include<algorithm>
int a1,b1;
char a2[12];
char b2[12];
bool _1(){
	return a1==b1;
}
bool _2(){
	return _1()&&a2[1]==b2[1]&&a2[2]==b2[2];
}
bool t(){
	bool t1=(a2[3]=='A'||a2[3]=='B'||a2[3]=='C')&&(b2[3]=='A'||b2[3]=='B'||b2[3]=='C');
	bool t2=(a2[3]=='D'||a2[3]=='F')&&(b2[3]=='D'||b2[3]=='F');
	return t1||t2;
}
bool _3(){
	return _2()&&t();
}
int abs(int x){
	if(x<0)return-x;
	return x;
}
bool _4(){
	if(!_3())return false;
	if(abs(a2[3]-b2[3])==1)return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&a1);
	scanf("%s",&a2[1]);
	scanf("%d",&b1);
	scanf("%s",&b2[1]);
	/*printf("a1b1:%d%d\n",a1,b1);
	for(int i=1;a2[i];i++)printf("%c",a2[i]);
	puts("");
	for(int i=1;b2[i];i++)printf("%c",b2[i]);
	puts("");*/
	
	printf("%d%d%d%d",_1(),_2(),_3(),_4());
	return 0;
}
//g++ x.cpp -o x -O2 -std=c++14 -Wall && time ./x && size x
//Trick||Treat!
