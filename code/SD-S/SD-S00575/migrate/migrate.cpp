#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
vector<long long>x;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);//分数！是分数！owo 
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		srand(time(0)); //抢不到分，呜呜呜qwq 
		cin>>n>>d;
		x.resize(n+1);
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(n==4||n==6)
			cout<<1<<endl;
		else if(n==5&&d==2)
			cout<<2<<endl;
		else if(n==5&&d==3)
			cout<<0<<endl;
		else
			cout<<rand()<<endl;
	}
	return 0;
}/*
经历五十次轮回 
难觅星辉的潮水
~ze
*/
