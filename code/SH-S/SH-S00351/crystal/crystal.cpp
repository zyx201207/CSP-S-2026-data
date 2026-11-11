#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define Size 500005
int n,m;
int data[Size],sum[Size],cha[Size];

bool check(int x){
	for(int i=1;i<=n-x;i++){
		int end=i+x-1,cost=0;
		int mid=i+end>>1;
		for(int j=i;j<=end;j++){
			cost+=abs(data[j]-data[mid]);	
		} 
		if(cost<=m) return true;
	}
	return false;
}
void spj(){
	int res=1;
	int div=cha[2];
	int mid=n/2+1;
	for(int i=1;mid+i<=n && mid>=i;i++,div+=cha[2]){
		if(m>=2*div){
			res+=2,m-=div*2;
		}else if(m>=div){
			res++,m-=div;
		}else{
			break;
		}
	}
	if(n%2==0){
		if(m>=div) res++;
	}
	cout<<res<<endl;
	
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>data[i];
	sort(data+1,data+n+1);
	int sp=1;
	for(int i=1;i<=n;i++){
		if(i==1){
			cha[i]=0; continue;
		} 
		cha[i]=data[i]-data[i-1];
		if(cha[i]!=cha[i-1] && i!=2){
			sp=0;
			break;
		}
	}
	if(sp==1)
		spj();
	
	else{
		int l=1,r=n;
		
		while(l+1<r){

			int mid=(l+r)>>1;
			if(check(mid))
				l=mid;
			else
				r=mid-1;
		} cout<<l<<endl;
	}
		
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

