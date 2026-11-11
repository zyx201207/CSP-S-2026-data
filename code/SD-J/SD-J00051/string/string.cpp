#include<bits/stdc++.h>
using namespace std;
const int N=5e5+370;
struct{
	int m;char c;	
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].m>>a[i].c;
	} 
	for(int i=0,j=n-1;i<j;){
		if(a[i].c==a[j].c){
			if(a[i].m>a[j].m){
				a[i].m-=a[j].m;a[j].m=0;j--;
			}else{
				a[j].m-=a[i].m;a[i].m=0;i++;
			}
		}else{
			if(a[i].m>a[j].m){
				a[i].m-=a[j].m;cnt+=a[j].m;j--;
			}else{
				a[j].m-=a[i].m;cnt+=a[i].m;i++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
