#include <bits/stdc++.h>
using namespace std;
struct node{
	char cha;
	long long leng;
}a[20010];
char s;
int n,le,ri;
long long l,re;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	re=0;
	le = 0;
	ri = n-1;
	for(int i=0;i<n;i++){
		cin>>l>>s; 
		a[i].cha=s;
		a[i].leng=l;
		}
		int i = 0;
		while(le<ri){
			if(le-ri==-1){
				re+= min(a[le].leng,a[ri].leng);
				break;
			}
			if(a[le].cha!=a[ri].cha){
				if(a[le].leng>a[ri].leng){
					re+=a[ri].leng;
					a[le].leng-=a[ri].leng;
					ri--;
				}if(a[le].leng<a[ri].leng){
					re+=a[le].leng;
					a[ri].leng-=a[le].leng;
					le++;
			}else{
				re+=a[le].leng;
				le++;
				ri--;
			}
		}else{
			if(a[le].leng>a[ri].leng){
					a[le].leng-=a[ri].leng;
					ri--;
				}if(a[le].leng<a[ri].leng){
					a[ri].leng-=a[le].leng;
					le++;
			}else{
				le++;
				ri--;
		}
	}
}
	cout<<re;
	return 0;
} 
