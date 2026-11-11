#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100001],k[100001],t[100001][100001],a[100001][100001],x[100001],y[100001];
long long s[100001];
long long ccc(long long dz,long long dx){//dz后哪可以换线,不行则为-1 
	for(int i=dz;i<k[dx]/2;i++){
		for(int j=0;j<n;j++){
			for(int ff=0;ff<k[dx]/2;ff++){
				if(a[dx][i]==a[j][ff])return i;
			}
		}
	}
	return -1;
}
long long bbb(long long dz){//dz在哪一线路 
	for(long long i=0;i<n-1;i++){
		for(int j=0;j<k[i]/2;j++){
			if(a[i][j]==dz)return i;
		}
	}
	return n-1;
}
long long ddd(int dz){//找下标 
	for(int i=0;i<k[bbb(dz)];i++){
		if(a[bbb(dz)][i]==dz)return i;
	}
}
long long aaa(long long dx,long long dz,long long f){
	if(bbb(y[f])==dx&&ccc(dz,dx)==-1)return t[dx][dz];
	else if(ccc(dz,dx)>=0){
		return min(aaa(ccc(dz,dx),dz,f),aaa(dx,ccc(dz,dx)+1,f));
	}
	else return 9999999;
}
int main()
{
	freopen(subway.in,"r",stdin);
	freopen(subway.out,"w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=0;i<m;i++)cin>>w[i];
	for(long long i=0;i<n;i++){
		cin>>k[i];
		for(long long j=0;j<k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(long long i=0;i<q;i++){
		int t=0;
		cin>>x[i]>>y[i];
		t+=w[x[i]]+w[y[i]];
		t+=aaa(bbb(x[i]),ddd(x[i]),i);
		s[i]=t;
    }
	for(int i=0;i<q;i++)cout<<s[i]<<endl;
	return 0;
}