#include<bits/stdc++.h>
using namespace std;

int n,m;
long long x[500010];

long long maxx=0;

bool ck(){
	
	int fl=abs(x[2]-x[1]);
	
	for(int i=3;i<=n;i++){
		if(abs(x[i]-x[i-1])!=fl){
			return 0;
		}
	}
	return 1;
	
} 

int ohh(){
	long long fl=x[n/2];
	long long mt=m;
	long long cnt=0;
	if(n%2==1){
		cnt=1;
	}
	for(int j=n/2;j>=1;j--){
		if(mt-abs(fl-x[j])>=0){
			cnt++;
			mt-=abs(fl-x[j]);
		}else{
			break;
		}
	}
	cout << cnt;
	return 0; 
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	
	if(ck()){
		ohh();
		return 0;
	}
	
	sort(x+1,x+n+1);
	
	for(int i=1;i<=n;i++){
		long long fl=x[i];
		long long mt=m;
		long long cnt=0;
		for(int j=i;j>=1;j--){
			if(mt-abs(fl-x[j])>=0){
				cnt++;
				mt-=abs(fl-x[j]);
			}else{
				break;
			}
		}
		maxx=max(maxx,cnt);
	} 
	cout << maxx;
	
	return 0;
	
} 
