#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],Max=INT_MIN,he;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	he=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(m==1)Max=max(a[i],Max);
		if(n==m)he&=a[i];
	}
	if(m==1)cout<<Max;
	else if(m==n)cout<<he;
	else if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)	
				Max=max(Max,a[i]&a[j]);
		cout<<Max;
	}
	return 0;
}
//25分骗分代码，如果暴力可能0；正解应该是dp 
//建议升黑
 
