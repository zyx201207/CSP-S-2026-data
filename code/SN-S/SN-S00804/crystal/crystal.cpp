#include<fstream>
typedef long ll;
using namespace std;
ll a[500000],tong[200000];
int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	ll n,m;
	fin>>n>>m;
	
	
	ll Min=100000000000000,Max=-100000000000000;
	
	for(ll i=0;i<n;i++)
	{
		fin>>a[i];
		if(a[i]<Min)Min=a[i];
		if(a[i]>Max)Max=a[i];
	}
	if(Max-Min<=200000&&Max<100000&&Min>-100000){		//数字集中，桶排序 
		for(ll i=0;i<n;i++)tong[a[i]+100000]++;
		ll p=0;
		for(ll i=Min+100000;i<=Max+100000;i++){
			while(tong[i]>0){
				a[p++]=i-100000;
				tong[i]--;
			}
		}
	}
	else{				//不满足条件，冒泡排序 
		for(ll i=0;i<n;i++)
			for(ll j=0;j<i;j++)
				if(a[i]<a[j])
				{
					ll t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
	}
	ll sum=a[1]-a[0],tsum,j=0,ans=-1000,t,last=a[0];
	for(ll i=a[1];i<=a[n-1];i++){
		//if(a[i]==last){
		//	ans++;
		//	continue;
		//}
		//fout<<"i= "<<i;
		sum+=j;
		for(;a[j]<=i&&j<n;j++);
		//fout<<" sum="<<sum<<" a[j]="<<a[j];
		t=0;tsum=sum;
		while(tsum>m)
		{
			tsum-=i-a[t];
			t++;
		}
		//while(a[t]==a[t+1])t++;
		//fout<<" t="<<t;
		ans=max(ans,j-t);
		//fout<<" ans="<<ans<<endl;
		//last=a[i];
	}
	
	fout<<ans;
	
	
	return 0;
}
