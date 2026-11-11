#include<bits/stdc++.h>

using namespace std;



ifstream fin("crystal.in");

ofstream fout("crystal.out");

#define cin fin

#define cout fout



using i64=long long;

const int N=5e5+5;



i64 n,m,a[N];



signed main(){

	cin>>n>>m;

	for(int i=1;i<=n;++i)

		cin>>a[i];

	sort(a+1,a+1+n);

	i64 use=0,ans=0;

	for(i64 lp=1,mid=1;mid<=n;++mid){

		use+=(a[mid]-a[mid-1])*(mid-lp);

		while(use>m) use-=a[mid]-a[lp++];

		ans=max(ans,mid-lp+1);

	}

	cout<<ans<<endl;

	return 0;

}



struct Code{

	Code(){ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); }

	~Code(){ fout.flush(),fin.close(),fout.close(); }

} wtl;

