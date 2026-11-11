#include<bits/stdc++.h>
using namespace std;
void _file(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
}
long long n,m,mxsize,num;
string ans;
long long sumer;
bool flb;
string s[200010];
long long stk[200010];
int main(){
	_file();
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		long long x;
		cin>>x;
		while(x){
			s[i]+=x%2+'0';
			x/=2;
		}
		reverse(s[i].begin(),s[i].end());
		long long tmp=s[i].size()-1;
		mxsize=max(mxsize,tmp);
	}
	for(long long i=1;i<=n;i++){
		string hh="";
		for(long long j=s[i].size();j<=mxsize;j++){
			hh+='0';
		}
		s[i]=hh+s[i];
	}
	for(long long i=0;i<=mxsize;i++){
		if(!flb){
			long long cnt=0;
			stack<long long> ack;
			for(long long j=1;j<=n;j++){
				if(s[j][i]=='1'){
					ack.push(j);
					cnt++;
				}
			}
			if(cnt>=m){
				num=ack.size();
				while(!ack.empty()) stk[ack.top()]=1,ack.pop();
				flb=1;
				ans+='1';
			}			
		}
		else{
			stack<long long> ack;
			for(long long j=1;j<=n;j++){
				if(s[j][i]=='0'&&stk[j]){
					ack.push(j);
				}
			}
			if(num-ack.size()>=m){
				while(!ack.empty()) stk[ack.top()]=0,ack.pop();
				num-=ack.size();
				ans+='1';
			}else{
				ans+='0';
			}
		}
	}
	long long tp=1;
	for(long long i=ans.size()-1;i>=0;i--){
		sumer+=(ans[i]-'0')*tp;
		tp*=2;
	}
	cout<<sumer;
	return 0;
}

/*
5 3
31 3 1 15 7
*/
