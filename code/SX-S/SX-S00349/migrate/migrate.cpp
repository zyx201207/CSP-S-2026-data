#include<bits/stdc++.h>
using namespace std;
#define int long long
int gunmu,T,n,d,a[2000010],cl[2000010],cr[2000010];
bitset<5010> bs[5010];
unordered_map<int,int> numset;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>gunmu>>T;
	if(gunmu==13 or gunmu==14){
		while(T--){
			cin>>n>>d;
			for(int i=0;i<=n+5;i++)cl[i]=cr[i]=a[i]=0;
			for(int i=1;i<=n;i++)cin>>a[i];
			int l=1,r=1;
			for(int i=1;i<=n;i++){
				while(l+1<=i and a[i]-a[l]>d)l++;
				while(r+1<=n and a[r+1]-a[i]<=d)r++;
				cl[i]=l;
				cr[i]=r;
			}
			int ans=0;
			for(int s=1;s<=n;s++){
				int q=cr[s]-1;
				if(q<=s)continue;
				int t=cr[q];
				if(cl[t]==q)ans++;
			}
			cout<<ans<<endl;
		}
	}else if(gunmu==11 or gunmu==12){
		while(T--){
			cin>>n>>d;
			for(int i=0;i<=n+5;i++)cl[i]=cr[i]=a[i]=0;
			for(int i=1;i<=n;i++)cin>>a[i];
			int l=1,r=1;
			for(int i=1;i<=n;i++){
				while(l+1<=i and a[i]-a[l]>d)l++;
				while(r+1<=n and a[r+1]-a[i]<=d)r++;
				cl[i]=l;
				cr[i]=r;
			}
			int ans=0;
			for(int s=1;s<=n;s++){
				int q=cr[s]-1;
				if(q<=s)continue;
				int t=cr[q];
				if(cl[t]==q){
					int ansl=0,pla=s;
					while(cr[cl[pla]]==pla){
						pla=cl[pla];
						ansl++;
					}
					int ansr=0;
					pla=t;
					while(cl[cr[pla]]==pla){
						pla=cr[pla];
						ansr++;
					}
					ans+=ansr*ansl;
				}
			}
			cout<<ans<<endl;
		}
	}else{
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(bs[i][j]==1)bs[i][j].flip();
			numset.clear();
			for(int i=1;i<=n;i++){
				cin>>a[i];
				numset[a[i]]=i;
			}
			int l=1,r=1;
			for(int i=1;i<=n;i++){
				while(l+1<=i and a[i]-a[l]>d)l++;
				while(r+1<=n and a[r+1]-a[i]<=d)r++;
				for(int j=l;j<=r;j++)bs[i][j].flip();
				for(int j=i+2*d;;j+=d){
					if(numset.count(j))bs[i][numset[j]].flip();
					else break;
				}
				for(int j=i-2*d;;j-=d){
					if(numset.count(j))bs[i][numset[j]].flip();
					else break;
				}
			}
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++)cout<<bs[i][j];
//				cout<<endl;
//			}
			int ans=0;
			bitset<5010> qwe,num;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)if(qwe[j]==1)qwe[j].flip();
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d)continue;
					num=bs[i]&bs[j]&qwe;
					if(qwe.count()==2)ans++;
					qwe[j].flip();
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/