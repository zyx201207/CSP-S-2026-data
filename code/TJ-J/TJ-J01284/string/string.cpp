#include<bits/stdc++.h>
using namespace std;
const int m=2e5+1;
long long n,l,s,last;
long long cnt;
long long a[m],a1[m];
char b[m],b1[m];
bool flag;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ont","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	a1[1]=a[1];
	b1[1]=b[1];
	last=2;
	l++;
	for(int i=1;i<=n;i++){
		for(int j=last;j<=n;j++){
			if(j==n){
				flag=1;
			}
			if(b1[i]==b[j]){
				a1[i]+=a[j];
			}else{
				b1[i+1]=b[j];
				a1[i+1]=a[j];
				l++;
				last=j+1;
				break;
			}
			
		}
		if(flag==1){
			flag=0;
			break;
		}
	}
	for(int i=1;i<=l/2;i++){
		int k=l-i+1;
		if(b1[i]==b1[k]){
			if(a1[i]!=a1[k]){
				cnt+=abs(a1[i]-a1[k]);
			}	
		}else{
			cnt+=min(a1[i],a1[k]);
			if(a1[i]>a1[k]){
				if(abs(a1[i]-a1[k])<a1[k-1]){
					a1[k-1]-=abs(a1[i]-a1[k]);
					cnt+=abs(a1[i]-a1[k]);
				}
			}else if(a1[i]<a1[k]){
				if(abs(a1[i]-a1[k])<a1[i+1]){
					a1[i+1]-=abs(a1[i]-a1[k]);
					cnt+=abs(a1[i]-a1[k]);
				}
			}
		}
	}
	cout<<cnt; 
	return 0;
} 
