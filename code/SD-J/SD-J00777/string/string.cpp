#include<bits/stdc++.h>
using namespace std;
struct q{
	long long a;
	char c;
}a[201000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,j;
	long long s=0,w=0;
	cin>>n;
	j=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	for(int i=1;i<j;i++){ 
		while(a[i].a!=0&&j>i){
			if(a[i].c==a[j].c){
				if(a[i].a>=a[j].a){
					a[i].a-=a[j].a;
					a[j].a=0;
					j--;
				}else{
					a[j].a-=a[i].a;
					a[i].a=0;	
				}
			}else{
				if(a[i].a>=a[j].a){
					s+=a[j].a;
					a[i].a-=a[j].a;
					a[j].a=0;
					j--;
				}else{
					s+=a[i].a;
					a[j].a-=a[i].a;
					a[i].a=0;	
				}
			}
			
		}
	}	
	cout<<s;
} 
