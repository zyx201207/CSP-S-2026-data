#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long ans;
	string s;
}x[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].ans>>x[i].s;
	}
	long long i=1,j=n;
	while(i<j){
		//cout<<i<<" "<<j<<" "<<sum<<"\n";
		if(x[i].ans<=0) i++;
		if(x[j].ans<=0) j--;
		if(x[i].ans<=x[j].ans){
			if(x[i].s!=x[j].s){
				sum+=x[i].ans;
			}
			x[j].ans-=x[i].ans;
			x[i].ans=0;
		}
		else{
			if(x[i].s!=x[j].s){
				sum+=x[j].ans;
			}
			x[i].ans-=x[j].ans;
			x[j].ans=0;
		}
	}
	cout<<sum;
}
