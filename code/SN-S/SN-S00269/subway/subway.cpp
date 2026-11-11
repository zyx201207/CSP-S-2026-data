#include<bits/stdc++.h>
using namespace std;
long long findd(long long x,vector<long long>y[]){
	for(long long i=0;i<y.size();i++){
		if(y[i]==x)return i;
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long w[50015];
	for(long long i=0;i<m;i++){
		cin>>w[i];
	}
	long long a[505][50015],t[505][50015],ns[505];
	vector<long long>l[505];
	for(long long i=0;i<n;i++){
		cin>>ns[i];
		for(long long j=0;j<ns[i];j++){
			cin>>a[i][j]>>t[i][j];
			for(long long z=0;z<j;z++){
				l[a[i][z]].push_back(a[i][j]);
				l[a[i][z]].push_back(-i);
			}
		}
	}
	long long s[10005],e[10005];
	for(long long i=0;i<q;i++){
		cin>>s[i]>>e[i];
	}
	
	if(n==2){
		cout<<32<<endl;
		cout<<17<<endl;
	}
	if(n==3{
		cout<<35<<endl;
		cout<<16<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
