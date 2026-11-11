#include<bits/stdc++.h>
using namespace std;
//struct d{
//	int a;
//	int id;
//};
//bool cmp(d x,d y){
//	if(x.a==y.a) return x.id>y.id;
//	return x.a>y.a;
//}
//d s[300005];
int o[300005];
int q[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,maxid=0;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>s[i].a;
//		s[i].id=i;
//	}
//	sort(s+1,s+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		if(s[i].a==s[i-1].a){
//			maxid=s[i].id;
//		}else if(s[i].a==s[i+1].a){
//			
//		}
//	}
//	for(int i=1;i<=n;i++){
//		if(maxid>=i && ){
//			for(int j=maxid;j<=n;j++){
//				o[s[j].a]+=1;
//			}
//		}else{
//			for(int j=i;j<=n;j++){
//				o[s[j].a]+=1;
//			}
//		}
//	}
//	for(int i=1;i<=m;i++){
//		cout<<o[i]<<" ";
//	}
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>o[i];
	}
	int t=0;
	for(int i=0;i<n;i++){
		for(int j=t;j<i;j++){
			if(o[j]==o[i]){
				for(int k=j;k<i;k++){
					o[k]=-1;
				}
			}
		}
		for(int j=t;j<n;j++){
			q[o[j]]+=1;
		}
		t++;
	}
	for(int i=0;i<m;i++){
		cout<<q[i]<<" ";
	}
	return 0;
}
