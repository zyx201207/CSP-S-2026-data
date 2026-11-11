#include<bits/stdc++.h>
using namespace std;
int n,t,ppl,cnt=1,maxx,rt;
long long m,a[500005],kkk,qwq,mm;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i==2){
			kkk=a[2]-a[1];
		}
		if(i>2&&ppl==0){
			if(kkk!=a[i]-a[i-1]) ppl=1;
		}
	}
	if(ppl==0){
		qwq=kkk;
		while(m>=0&&cnt<=n){
			m-=qwq;
			cnt++;
			qwq+=kkk;
		}
		cnt--;
		cout<<cnt;
		return 0;
	}
	rt=2;
	mm=m;
	for(int i=1;i<n;i++){
		for(int o=rt;o<=n;o++){
			mm-=(a[o]-a[o-1])*(o-i);
			cout<<"i="<<i<<" "<<"mm="<<mm<<'\n';
			if(mm<0){
				rt=o;
				mm+=a[o]-a[i];	
				maxx=max(maxx,o-i);
				break;
			}
			
		}
	}
	cout<<maxx;	
} 
 