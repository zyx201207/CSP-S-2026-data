#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n;
unsigned long long m;
long long maxx=0,had[N];
long long cmp(long long x,long long y){
	return x<y; 
}
priority_queue<long long,vector<long long>,greater<long long> >lar;
priority_queue<long long>lez;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x;cin>>x;
		if(had[x]!=0){
			had[x]++;
			continue;
		}
		had[x]++;
		if(lez.empty()) lez.push(x);
		else	{
			if(x>lez.top())	lar.push(x);
			else if(x<lar.top())	lez.push(x);
		}
		if(lar.size()>lez.size()){
			lez.push(lar.top());
			lar.pop();
		}
			 
	}
	if(n==1){
		cout<<"1"<<endl;
		return 0; 
	}
	if(m==0){
		sort(had+1,had+n+1,cmp);
		cout<<had[1]<<endl;
		return 0;
	}
	long long mid=lez.top();
	lez.pop();
	while(m){
		if(had[lez.top()]){
			if(m>=(mid-lez.top())*had[lez.top()]){
				had[mid]+=had[lez.top()];
				had[lez.top()]=0;
				m-=(mid-lez.top())*had[lez.top()];
			}
			else{
				had[mid]+=m/(mid-lez.top());
				break;	
			}		
		}
		else lez.pop();
		
		if(lez.empty()&&m>0){
			maxx=max(maxx,had[mid]);
			lez.push(mid);
			if(!lar.empty()){
				mid=lar.top();
				lar.pop();
			}
			else{
				cout<<n<<endl;
				return 0;
			}
		}
	}
	sort(had+1,had+n+1,cmp);
	cout<<max(maxx,had[1])<<endl;
	return 0;	
}
