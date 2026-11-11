#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int cnt[300005];
vector<int> v;
vector<int> tmp;
int a;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		tmp.clear();
		tmp.push_back(v[i]);
		for(int j=i+1;j<n;j++){
			for(int k=0;k<(int)tmp.size();k++)
			{
				if(tmp[k]==v[j])
				{
					tmp.erase(tmp.begin()+k,tmp.end());
					break;
				}
			}
			tmp.push_back(v[j]);
		}
		for(int j=0;j<(int)tmp.size();j++)
		{
			cnt[tmp[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i];
		if(i!=m)cout<<" ";
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}