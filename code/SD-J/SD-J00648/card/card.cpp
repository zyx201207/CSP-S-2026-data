#include<bits/stdc++.h>
using namespace std;
const int mn=5e5+5;
int t[mn],a[mn],st[mn],ans[mn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int head=0;
		for(int j=i;j<=n;j++){
			st[++head]=a[j];
			if(t[a[j]]){
				do{
					head--;
					t[st[head]]--;
//					cout<<"^^!";
				}while(st[head]!=a[j]);
//				cout<<st[head]<<"&&";
				t[a[j]]++;
			}else{
				t[a[j]]++;
//				st[++head]=a[j];
			}
			
		}
		for(int j=0;j<=m;j++){
			t[j]=0;
		}
//		for(int j=1;j<=head;j++){
//			cout<<st[j]<<" ";
//		}
//		cout<<"\n";
		for(int j=1;j<=head;j++){
			ans[st[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}//sto   CCF   orz   ¶à¸øµãßÂ¡£ 
