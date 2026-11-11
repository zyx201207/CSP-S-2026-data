#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
long long n,m,s=pow(2,40),ans=pow(2,40)-1;
long long a;
vector<long long>v;
vector<long long>dv;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a,v.push_back(a);
	while(s>0){
		long long k=0;
		for(long long i=0;i<v.size();i++)
			if((v[i]&s)==s)
				k++;
		bool f=0;
		if(k>=m)
			f=1;
		if(f){
			for(long long i=0;i<v.size();i++)
				if((v[i]&s)==s)
					dv.push_back(v[i]);
			v.clear();
			for(long long i=0;i<dv.size();i++)
				v.push_back(dv[i]);
			dv.clear();
		}
		if(v.size()==m)
			break;
		s>>=1;
	}
	for(long long i=0;i<v.size();i++)
		ans&=v[i];
	cout<<ans;
	return 0;
}
