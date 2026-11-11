//#include<bits/stdc++.h>
//using namespace std;
//int pre[2000001],suf[2000001];
//int nxt[2000001];
//vector<int>fnxt[2000001];
//int ansl[2000001];
//int sx[2000001];
//void dfsp(int x){
//	if(fnxt[x].size()==0){
//		pre[x]=1;
//		return ;
//	}
//	dfsp(fnxt[x][0]);
//	fnxt[x]=fnxt[x][0];
//	for(auto y:fnxt[x1]){
//		if(sx[x1+1]-sx[y]>d)
//			fnxt[x]++;
//	}	
//}
//int main(){
//	int c,t;
//	cin>>c>>t;
//	while(t--){
//		int n,d;
//		cin>>n>>d;
//		for(int i=1;i<=n;i++)
//			cin>>sx[i],fnxt[i].clear();
//		for(int i=1;i<=n;i++){
//			nxt[i]=nxt[i-1];
//			while(nxt[i]<n&&sx[nxt[i]+1]-sx[i]<=d)
//				nxt[i]++;
//			fnxt[nxt[i]].push_back(i);
//		}
//		for(int i=1;i<=n;i++){
//			if(!pvis[i]){
//				pvis[i]=1;
//				dfsp(i);
//			}
//		}
//		for(int i=1;i<n;i++){//i 枚举分界线
//			int x1=i+1,ans1=0;//往前跳的指针
//			while(1){
//				if(fnxt[x1].size()==0)
//					break;
//				else{
//					for(auto y:fnxt[x1]){
//						if(sx[x1+1]-sx[y]>d)
//							ans1++;
//					}
//					x1=fnxt[x1][0];
//				}
//			}
//		}
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
long long sx[2000001];
vector<int>vc;long long d;
bool pd(int len,int c){//迂回是否成功
	if(sx[vc[len-1]]-sx[vc[len-2]-c]>d)
		return 0;
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=10){
		while(t--){
			int n;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>sx[i];
			int flag=0,ans=0;
			for(int i=1;i<=n;i++){
				vc.clear();
				vc.push_back(i);
				int len=1,cnt=0;
				for(int j=i+1;j<=n;j++){
					if(sx[j]-sx[j-1]>d)
						break;
					if(j==n||sx[j+1]-sx[vc[len-1]]>d){
						vc.push_back(j),len++;
						if(len>=3){
							if(pd(len,1)){
								cnt++;
								if(pd(len,2))
									cnt++;
							}
						}
						if(cnt==1)
							ans++;//cout<<i<<" "<<j<<endl;
					}else{
						vc.push_back(j),len++;
						if(len>=3){
							if(pd(len,1)){
								cnt++;
								if(pd(len,2))
									cnt++;
							}
						}	
						if(cnt==1)
							ans++;//cout<<i<<" "<<j<<endl;
						if(len>=3){
							if(pd(len,1)){
								cnt--;
								if(pd(len,2))
									cnt--;
							}
						}				
						vc.pop_back(),len--;					
					}
				}
			}
			cout<<ans<<endl;			
		}
	}else if(c<=12){
		ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
		while(t--){
			int n;
			cin>>n>>d;
			long long gc;
			cin>>gc;
			for(int i=2;i<=n;i++){
				long long x;
				cin>>x;
				if(i==2)
					gc=x-gc;
			//	cout<<i<<endl;
			}
			long long cnt=d/gc;
			if(cnt>=n||cnt<=1)
				cout<<0<<endl;
			else
				cout<<max(0ll,n-(cnt*2-1))<<endl;
		}
	}
	return 0;
}