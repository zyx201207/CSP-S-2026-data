#include<bits/stdc++.h>
using namespace std;
int n;
struct no{
	int m;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
		sum+=a[i].m;
	}
	long long ans=0;
	for(int i=1;i<=sum/2;i++){
		int aq=0,ap=sum+1;
		int k=0,j=n+1;
		while(aq<i){
			k++;
			aq+=a[k].m;
		}
		while(ap>sum-i+1){
			j--;
			ap-=a[j].m;
		}
		if(a[k].c!=a[j].c){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
