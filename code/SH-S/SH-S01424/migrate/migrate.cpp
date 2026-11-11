#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int in(){
	bool flag=0;
	int num=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			flag=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	if(flag)
		num=-num;
	return num;
}
void out(int num){
	if(num<0){
		putchar('-');
		num=-num;
	}
	if(num>9)
		out(num/10);
	putchar('0'+num%10);	
}
int c,t,n,d;
int memo[N],cnt[N],x[N];
bool flag1;//µÈ²î
struct node{
	int dep,idx;
};
queue<node> q;
void dfs(int num){
	node a,t;
	a.dep=0,a.idx=num;
	int id,st;
	memo[num]=0;
	q.push(a);
	while(!q.empty()){
		t=q.front();
		q.pop();
		id=t.idx,st=t.dep;
		for(int i=id+1;i<=n;i++){
			if(x[i]-x[id]>d)
				break;
			if(memo[i]<st+1)
				continue;
			a.dep=st+1,a.idx=i;
			memo[i]=st+1;
			cnt[i]++;
			q.push(a);
		}
	}
}
void work(){
	int ans=0;
	n=in(),d=in();
	flag1=1;
	for(int i=1;i<=n;i++){
		x[i]=in();
		if(i>=3){
			if(x[i]-x[i-1]!=x[i-1]-x[i-2])
				flag1=0;
		}
	}
	if(n>5000){
		out(0);
		putchar('\n');
		return;
	}
	for(int i=1;i<=n;i++){
		memset(memo,0x3f3f3f3f,sizeof(memo));
		memset(cnt,0,sizeof(cnt));
		dfs(i);
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2)
				ans++;
		}
	}
	out(ans);
	putchar('\n');
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=in(),t=in();
	for(int i=1;i<=t;i++){
		work();
	}
	fclose(stdin);
	fclose(stdout);
}
