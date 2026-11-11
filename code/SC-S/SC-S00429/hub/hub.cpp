#include<bits/stdc++.h>
using namespace std;
//zhengzaixiedongxi
//fanzhengT4xiebyulai
//burushitushang
//mihuoxingweidashang
//zhendeyourenhuinong
//womensichuandedashangma
//buzhidao
//114514
//#include<bits\stdc++.h>
//int mian()
//freopen("hub.in","w",stdout);
//freopen("hub.out","r",stdin);
//woshinailong
//wocaishinailong 
//gunmu
//shangmiandeshi
//kongbaifengefu
//suanlesuibiancaiyige
//yiyanjiadeguilvedele
int num,t,n,k,a;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>num>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for(int j=1;j<n;j++)cin>>a>>a;
		cout<<(n-k)/2<<'\n';
	}
	return 0;
}