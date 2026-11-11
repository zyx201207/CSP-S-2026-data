//SN-S00449 冯睦子 西安市渭北中学 
#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> queb;
priority_queue<long long , vector<long long> , greater<long long> > ques;
queue<long long> que;
long long n,m,a[500007],high,cc,ans=1,d;
void qoqb(){
	while(!queb.empty()){
		if(queb.size()!=1)
			que.push(queb.top());
		queb.pop();	
	}while(!que.empty()){
		queb.push(que.front());
		que.pop();
	}
}void qoqs(){
	while(!ques.empty()){
		if(ques.size()!=1)
			que.push(ques.top());
		ques.pop();	
	}while(!que.empty()){
		ques.push(que.front());
		que.pop();
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			d=a[i]-a[i-1];
		}if(i!=2&&i!=1&&a[i]-a[i-1]!=d){
			cc=1;
		}
	}if(cc==0){
		for(int i=1;i<=n;i++){
			if(m>=(2*a[i]-(a[1]+a[i-1]))*(i-1)/2)
				ans=i;
		}cout<<ans;
		return 0;
	}for(int i=1;i<=n;i++){
		if(i!=1){
			if(a[i]==high){
				queb.push(a[i]);
				ques.push(a[i]);
			}else if(a[i]>high&&m>=(a[i]-high)*queb.size()){
				queb.push(a[i]);
				ques.push(a[i]);
				m-=(a[i]-high)*(i-1);
				high=a[i];
			}else if(a[i]>high&&m<(a[i]-high)*queb.size()){
				long long minf=ques.top();
				qoqb();
				ques.pop();
				if((a[i]-high)*(queb.size())<high-minf){
					m=m-high+minf+(a[i]-high)*(queb.size());
					ques.push(a[i]);
					queb.push(a[i]);
					high=a[i];
				}else{
					ques.push(minf);
					queb.push(minf);
				}				
			}else if(a[i]<high){
				long long mf=queb.top(),ms;
				queb.pop();
				qoqs();
				ms=queb.top();
				if(high-a[i]<(mf-ms)*queb.size()){
					high=ms;	
					queb.push(a[i]);
					ques.push(a[i]);
					m-=((mf-ms)*queb.size()-high+a[i]);
				}else{
					queb.push(mf);
					ques.push(mf);
				}	
			}
		}else{
			queb.push(a[i]);
			ques.push(a[i]);
			high=a[i];
		}
	}
	cout<<queb.size();
	return 0;
}
