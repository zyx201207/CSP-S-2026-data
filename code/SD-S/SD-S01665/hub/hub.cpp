#include<iostream>
#include<cstdio>
using namespace std;
bool Test_MLE_Start;
int _=1;
bool Test_MLE_End;
inline int reads(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}inline void clr(){
//	Don't Forget!

}inline void files(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}signed main(){
//	printf("%lf\n",(&Test_MLE_End-&Test_MLE_Start+1)/1024.0/1024.0);
//	files();
//	_=reads();
	while(_--){
		clr();
		
	}return 0;
}
