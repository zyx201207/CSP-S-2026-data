#include<bits/stdc++.h>
using namespace std;
int n=0,maxx=0,last=0;
bool checkb=1;
long long m=0, bcheck=0;
priority_queue <long long> b; 
stack <long long> num; 
long long fastread(){
	long long ch=getchar();
	long long t=0,check=1;
	if(ch=='-'){
		check=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		t=t*10+ch-('0');
		ch=getchar();
	}
	return t*check;
}
int fastprint(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		fastprint(x/10);
	}
	char ch=x%10+'0';
	putchar(ch);
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=fastread();
	m=fastread();
	for(int i=1;i<=n;i++){
		long long x=fastread(),bc=0;
		b.push(x);
		if(i>1)bc=x-last;
		if(i>2){
			if(bc!=bcheck)checkb=0;
		}
		bcheck=bc;
		last=x;
	}
	if(!checkb){
	for(int i=1;i<=n;i++){
		long long maxn=b.top(),cost=0;
		int cnt=1;
		b.pop();
		for(int j=1;j<=n-i;j++){
			if(cost+maxn-b.top()<=m){
				cost+=maxn-b.top();
				cnt++;
				num.push(b.top());
				//fastprint(b.top());
				//cout<<endl;
				b.pop();
			}
			else break;
		}
		for(int i=2;i<=cnt;i++){
			b.push(num.top());
			num.pop();
		}
		//fastprint(cnt);
		//cout<<" ";
		//fastprint(maxn);
		//cout<<endl;
		maxx=max(cnt,maxx);
		if(maxx>n-i)break;
	}
	fastprint(maxx);
	}
	else{
		if(bcheck==0)fastprint(n);
		else{
			if(bcheck<0)bcheck*=-1;
			for(int i=n;i>=1;i--){
				if(i*(i-1ll)/2<=m/bcheck){
					fastprint(i);
					break;
				}
			}
		}
	}
}
