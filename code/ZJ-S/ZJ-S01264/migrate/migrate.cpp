#include<bits/stdc++.h>
using namespace std;
int c,t;
queue<long long> q;
long long n,d,x2[2000005],x1[2000005],ans;
long long read(){
	char c;
	long long f=1,x=0;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	for(int p=1;p<=t;p++){
		n=read();
		d=read();
		for(int i=1;i<=n;i++){
			x2[i]=read();
		}
		for(int i=2;i<=n;i++){
			x1[i]=x2[i]-x2[i-1];
			q.push(x1[i]);
		}
		if(c==11||c==12){
			long long T=x1[2];
			int beishu=1;
			if(T>(d+1)/2){	
				cout<<0<<endl;
				continue;
			}else{
				while(T<(d+3)/4){
					T+=T/beishu;
					beishu+=1;
				}
				cout<<n/beishu-3<<endl;
			}
		}
		else{
			long long len=0,count=0;
			for(int i=2;i<=n;i++){
				if(q.front()<(d+1)/2&&count+q.front()<=d){
					count+=q.front();
					q.pop();
					if(count>(d+1)/2){
						len++;
					}
				}else if(q.front()>d){
					if(len>2){
						ans+=len-2;
					}
					
					len=0;
					q.pop();
				}else{
					len++;
					q.pop();
				}
			}
			if(len>2){
				cout<<ans+len-2<<endl;
			}else{
				cout<<ans<<endl;
			}
		}	
	}
	return 0;
}
