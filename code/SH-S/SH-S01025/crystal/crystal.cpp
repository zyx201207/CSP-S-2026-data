#include<bits/stdc++.h> 
using namespace std;
int n,maax,cnt;
long long m,a,b,ans,c,d,ccnt,mxccnt;
int t[200010];
int mx[200010];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a;
		b=a+100005;
		t[b]++;
	}
	for (int i=0;i<200010;i++){
		if(t[i]>maax){
			maax=t[i];
		}
	}
	for (int i=0;i<200010;i++){
		if(t[i]==maax){
			mx[cnt]=i;
			cnt++;
		}
	}
	for (int i=0;i<cnt;i++){
		ccnt=0;
		ans=0;
		for (int j=1;j<=m;j++){
			c=mx[i]-j;
			if(c<0) break;
			ans+=j*t[c];
			ccnt+=t[c];
			if(ans>m){
				d=(ans-m)/j;
				if((ans-d*j)>m) d++;
				ccnt-=d;
				ans=ans-d*j;
				break;
			}
			
		}
		if(ccnt>mxccnt){
			mxccnt=ccnt;
		}
		
	}
	cout<<mxccnt+maax;
	return 0; 
}
