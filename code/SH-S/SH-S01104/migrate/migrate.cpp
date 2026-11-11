#include<bits/stdc++.h>
using namespace std;
int c,T;
long long qread(){
	char c=getchar();
	int flag=1;
	long long x=0;
	if(c=='-'){
		flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return flag*x;
}
void qwrite(long long ans){
	string s="";
	if(ans==0){
		putchar('0');
		putchar('\n');
		return;
	}
	while(ans!=0){
		char c=ans%10+'0';
		ans/=10;
		s=c+s;
	} 
	for(int i=0;i<s.size();i++){
		putchar(s[i]);
	}
	putchar('\n');
}
void solve2(){
	while(T--){
		long long n,d;
		n=qread();
		d=qread();
		long long x[n];
		for(int i=0;i<n;i++){
			x[i]=qread();
		}
		int final=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int cur=i;
				int cnt=0,c,ans=0;
				while(cur<j){
					int k=cur+1;
					while(k<=j&&x[cur]+d>=x[k]){
						k++;
					} 
					k--;
					if(cur==k){
						break; 
					}
					cnt++;
					cur=k;
				}
				queue<pair<int,int> > q;//idx cnt
				q.push({i,0});
				while(!q.empty()){
					cur=q.front().first;
					if(cur!=j&&q.front().second>cnt){
						break;
					}
					if(cur!=j&&q.front().second>=cnt){
						q.pop();
						continue;
					}
					if(cur==j&&q.front().second==cnt){
						q.pop(); 
						ans++;
						continue;
					}
					if(ans>2){
						break;
					}
					int k=cur+1;
					while(x[cur]+d>=x[k]&&k<=j){
						q.push({k,q.front().second+1});
						k++;
					} 
					q.pop();
				}
				if(ans==2){
					final++;
				}
			}
		}
		cout<<final<<endl;
	}
}
long long x[2000005]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=qread();
	T=qread();
	c=11;
	if(c==11||c==12){
		while(T--){
			long long n,d;
			n=qread();
			d=qread();
			long long dis;
			for(int i=0;i<n;i++){
				x[i]=qread();
			}
			dis=x[n-1]-x[n-2];
			if(dis>d){
				qwrite(0);
				qwrite(d);
				qwrite(dis);
				continue;
			}
			int a=d/dis;
			long long ans=0;
			for(int i=1;i<n;i++){
				if(i%a==a-1){
					ans++;
				}
			}
			qwrite(ans);
			
		}
	}
	else{
		solve2();
	}
	return 0;
}

