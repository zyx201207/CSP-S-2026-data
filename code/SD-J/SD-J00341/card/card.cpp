#include<bits/stdc++.h>
//#define int long long
using namespace std;
int q[500010];
int x[500010];
int a[500010];
int f[500010];
int ctd[500010]; 
int ans[500010];
int xx[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	q[i]=i;f[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(x[a[i]]){
			q[i]=x[a[i]];
			for(int j=x[a[i]];j<=i;j++){
				x[a[j]]=0; 
			}
		}
		x[a[i]]=i;		
	}
//	for(int i=1;i<=n;i++){
//		cerr<<q[i]<<" ";
//	}cerr<<"\n";
	for(int i=1;i<=n;i++){
		if(q[i]!=i){
			//检查相连的对
			int k=q[i];
			while(1){
				f[k]=-1;
//				cerr<<k<<" and "<<q[k]<<" is not a free pair.[1]\n";
				k=q[k];
				if(q[k]==k)break;
			}
			//检查包裹的对
			for(k=i-1;k>=q[i]+1;k--){
				if(f[k]==1){
					f[k]=0;
				}
				ctd[k]++;
//				cerr<<k<<" and "<<q[k]<<" is not a free pair.[2]\n"; 
			} 
		}
	}
	
//	for(int i=1;i<=n;i++){
//		cerr<<f[i]<<" ";
//	}cerr<<"\n";
//	for(int i=1;i<=n;i++){
//		cerr<<ctd[i]<<" ";
//	}cerr<<"\n";
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			ans[a[i]]+=i;
			xx[i]=n-i;
		}
	}
	for(int i=1;i<n;i++){ 
//		切掉前i个
//		先找到这个的后继
		int hj=-1;
		for(int j=i+1;j<=n;j++){
			if(q[j]==i){
				hj=j;
			}
		}
		if(hj==-1){//没有后继，说明该数是一个对的末尾，不处理 
			continue; 
		}
//		cerr<<"AT "<<i<<" "<<hj<<"\n";
		//后继在hj的位置上，破坏一个数对，里面所有单层包裹的对变成自由对
		for(int j=i+1;j<hj;j++){
//			cerr<<j<<"\n";
			if(f[j]==0){//注意为-1的对不会变成自由对 
//				cerr<<"Chinese Can Fly\n";
				ctd[j]--;
//				cerr<<ctd[j]<<" "<<j<<"\n";
				if(ctd[j]==0){
//					if(i>=n-xx[j]+1)
						ans[a[j]]+=j-i;//一直到该点被删除前都为a[i]做贡献 
					f[a[j]]=1;
//					cerr<<j<<" to zero\n";
//					cerr<<"+"<<j-i<<"\n";
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

