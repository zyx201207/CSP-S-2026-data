#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
vector<pair<pair<long long,long long>,char> > vp;
int siz=0;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char b;
		cin>>a>>b;
		siz+=a;
		long long last=0;
		if(i>1)last=vp[i-2].first.second;
		vp.push_back({{last+1,last+a},b});
	}
	long long ans=0,siz2=siz/2;
	if(siz%2==1)siz2+=1;
	for(int i=0;i<=n&&i<vp.size();i++){
		if(vp[i].first.first<siz2&&vp[i].first.second>siz2)
		{
			vp.push_back({{siz2,vp[i].first.second},vp[i].second});
			vp[i].first.second=siz2-1;
			break;
		}
		else if(vp[i].first.second==siz2)
		{
			vp.push_back({{siz2,vp[i].first.second},vp[i].second});
			vp[i].first.second=siz2-1;
			break;
		}
		else if(vp[i].first.first==siz2)
		{
			vp.push_back({{siz2,vp[i].first.first},vp[i].second});
			vp[i].first.first=siz2+1;
			break;
		}
	}
 	sort(vp.begin(),vp.end());
//	for(int i=0;i<vp.size();i++)
//	cout<<vp[i].first.first<<" "<<vp[i].first.second<<" "<<vp[i].second<<endl;
	for(int i=0,j=vp.size()-1;i<=j;)
	{
		long long isize=vp[i].first.second-vp[i].first.first+1,
		jsize=vp[j].first.second-vp[j].first.first+1;
		long long istart=vp[i].first.first,jstart=vp[j].first.first;
		long long iend=vp[i].first.second,jend=vp[j].first.second;
		char ifu=vp[i].second,jfu=vp[j].second;
//		cout<<istart<<" "<<jstart<<endl;
		if(isize==jsize)
		{
			if(ifu!=jfu)ans+=isize;
			i++,j--;
			
		}
		else if(isize>jsize)
		{
			if(ifu!=jfu)ans+=jsize;
			vp[i].first.first+=jsize;
			j--;
			
		}
		else if(isize<jsize)
		{
			if(ifu!=jfu)ans+=isize;
			vp[j].first.second-=isize;
			i++;
		}
	}
	cout<<ans;
	return 0;
}