#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=-1;
struct aaa{
	long long num,cnt;
	bool operator<(const aaa&aa)const{
		return num<aa.num;
	}
};
vector<aaa>v;
bool a=true;
void boa(long long dt){
	long long ans=0,i=1,tm=m;
	for(;i<=n/2&&tm-2*i>=0;i+=dt)
		tm-=2*i,ans+=2;
	if(double(i)<n*0.5&&tm-i>=0)
		ans++;
	cout<<ans+1<<'\n';
	exit(0);
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		long long x,p=1e8;
		cin>>x;
		for(long long j=0;j<v.size();j++)
			if(x==v[j].num){
				p=j;
				break;
			}
		if(p==1e8)
			v.push_back({x,1});
		else v[p].cnt++;
	}
	sort(v.begin(),v.end());
	if(v.size()==1){
		cout<<v[0].cnt<<'\n';
		return 0;
	}
	long long dt=v[1].num-v[0].num;
	if(v[0].cnt!=1||v[1].cnt!=1)
		a=false;
	for(long long i=2;i<v.size();i++)
		if(v[i].num-v[i-1].num!=dt||v[i].cnt!=1)
			a=false;
	if(a)
		boa(dt);
	maxx=max(maxx,v[0].cnt);
	for(long long i=1;i<v.size();i++){
		long long tm=m,ans=0;
		for(long long j=i;j>=0;j--){
			long long x=v[i].num-v[j].num;
			if(tm>=x*v[j].cnt)
				tm-=x*v[j].cnt,ans+=v[j].cnt;
			else{
				while(tm-x>=0)
					tm-=x,ans++;
				break;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;	
}

