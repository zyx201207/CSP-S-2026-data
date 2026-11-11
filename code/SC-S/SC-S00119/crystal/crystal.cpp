#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500008],sum,maxx,q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=2;i<=n;i++){
//		b[i]=a[i]-a[i-1];
//	}
	long long t=1,w=1;
	q=a[1];
	for(long long i=1;i<n;i++){
		w++;
		sum+=(a[w]-q)*(w-t);//每一个点的贡献 
		q=a[w];
		while(t<w&&sum>m)sum-=q-a[t],t++;//这个点要加这么多 
		maxx=max(w-t+1,maxx); 
//		cout<<w<<" "<<t<<" "<<sum<<" "<<q<<" "<<maxx<<"\n";
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdin);
	return 0;
}