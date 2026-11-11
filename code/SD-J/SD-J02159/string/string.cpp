#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long sum,n,cur,ruc;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<long long>a(n+1);
	vector<char>c(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i],a[i]+=a[i-1];
		if(c[i]==c[i-1])a[i-1]=a[i],i--;
	}
	for(int i=1,j=n;a[i]<=a[n]/2;i++,j--){
		cur=a[i]-a[0],ruc=a[n]-a[j-1];//
		while(cur>0){
			sum+=ruc,cur-=ruc;
		}
		
	}
	cout<<sum;
	return 0;
}
/*
2017858858056828556
2017693937895526227
2017773320522414462
*/
