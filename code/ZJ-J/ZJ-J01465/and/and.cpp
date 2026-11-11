#include<bits/stdc++.h>
using namespace std;

/*

int n,m;
//long long a[200005];

int k[300];

long long mmax;

int wsm=-1;


struct node{
	long long mm,num;
	
}a[200005];

int tran(int x){
	
	int ans=0;
	
	bool store=0;
	if(x==mmax){
		store=1;
	}
	
	int bin[100];
	memset(bin,0,sizeof(bin));
	
	int now=0;
	
	while(x!=0){
		now++;
		bin[now]=x%2;
		x=x/2;
	}
	
	if(store==1){
		wsm=now;
	}
	
	for(int i=wsm;i>=1;i--){
		if(bin[i]==1){
			k[i]++;
		}
	}
	
	
	for(int i=wsm;i>=1;i--){
	//	cout<<bin[i];
		if(bin[i]==0){
			ans++;
		}else{
			break;
		}
	}
	
	
	//cout<<endl;
	return ans;
	
}

int cmp(node x,node y){
	return x.mm<y.mm;
}

bool vis[200005];
void search(int x,long long sum,int xz){
	if(xz==m){
		ans=max(ans,sum);
		//cout<<sum<<endl;
	}else{
		for(int i=x;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				search(i,sum&a[i],xz+1);
				vis[i]=0;
			}
		}
	}
}



int main(){
	
	//freopen("and3.in","r",stdin);
	
	mmax=INT_MIN;
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		
		mmax=max(mmax,a[i].num);
	}
	int tmp=tran(mmax);
	
	
	
	for(int i=1;i<=n;i++){
		a[i].mm=tran(a[i].num);
	}
	
	/*
	
	
	sort(a+1,a+1+n,cmp);
	/*
	for(int i=1;i<=n;i++){
		cout<<a[i].mm<<endl;
	}

	
	for(int i=wsm;i>=1;i--){
		k[i]--;
		if(k[i]<m){
			
			for(int i=1)
			
			break;
		}
	}
	
	
	
	
	
	
	return 0;
}


*/
int n,m;
long long a[200005];

long long ans;
bool vis[200005];
void search(int x,long long sum,int xz){
	if(xz==m){
		ans=max(ans,sum);
		//cout<<sum<<endl;
	}else{
		for(int i=x;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				search(i,sum&a[i],xz+1);
				vis[i]=0;
			}
		}
	}
}


void case7(){
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//ans=ans&a[i];
	}
	ans=a[1];
	for(int i=1;i<=n;i++){
		ans=ans&a[i];
		
	}
	cout<<ans<<endl;
}

void case6(){
	long long mmax=LONG_LONG_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmax=max(mmax,a[i]);
		//ans=ans&a[i];
	}
	
	cout<<mmax<<endl;
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	if(m==1){
		case6();
		return 0;
	}
	if(n==m){
		case7();
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	for(int i=1;i<=n;i++){
		search(i,a[i],0);
	}
	
	cout<<ans<<endl;
	
	
}


