#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll pre[200005]={0},ans=0;
int a[200005],n=0;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		pre[i]=pre[i-1]+a[i];
	} 
	int j=n,i=1;
	for(i=1;i<=j;i=i){
		if(a[i]<=a[j]){
			if(b[i]!=b[j])ans+=a[i];
			a[j]-=a[i];
			i++;
			if(a[j]==0)j--;
		}
		else{
			if(b[i]!=b[j])ans+=a[j];
			a[i]-=a[j];
			j--;
		}
	}
	cout<<ans;
	return 0;
}

