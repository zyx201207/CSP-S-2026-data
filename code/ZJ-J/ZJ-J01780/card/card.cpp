#include<bits/stdc++.h>
using namespace std;
int a[200005],d,n,m,mi,s[200005],s1[200005],s2[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int js=i+1;
		for(int i=1;i<=n;i++){
			s[i]=0;
			s2[i]=0;
		}
		s2[a[i]]++;
		for(int l=js;l<=n;l++){
			int k=a[l],z=-1;
			if(s2[k]==1){
				for(int j=l-1;j>=i;j--){
					if(a[j]==k&&s[j]==0){
						z=j;
						break;
					}
				}
			}else{
				s2[k]=1;
			}
			
			if(z!=-1){
				
//				cout<<z<<" "<<l-1<<" ";
				for(int j=z;j<=l-1;j++){
					s[j]=1;
				}
			}
			
		}
		for(int l=i;l<=n;l++){
//			cout<<s[l];
			if(s[l]==0){
				s1[a[l]]++;
			}
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<s1[i]<<" ";
	}
	return 0;
}
/*
第4题了
求求让我40分吧！ 
写代码ing...
emm..n`4 。 

 
优化一下。
现在大约n`3.
求求了

尽力了啊........ 
 
 我还不想退役！ 
 Trick||Treat!
 tui_yi||yi_de
 /ng_jiang!!!
 */ 
