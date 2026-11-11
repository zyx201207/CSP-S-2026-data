#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long sum=0;
	int j=n,i=1;
	while(i<j){
		if(a[i]>=a[j]){
			if(c[i]!=c[j]){
				sum+=a[j];
			}
			a[i]-=a[j];
			j--;
			if(a[i]==0){
				i++;
			}
		}else{
			if(a[i]<a[j]){
				if(c[i]!=c[j]){
				    sum+=a[i];
			    }
			    a[j]-=a[i];
			    i++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
