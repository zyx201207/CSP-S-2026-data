//11:24
//IT'S OVER

#include<bits/stdc++.h>
using namespace std;

//#define int long long

int a[500005];
int card[500005];
int nowp[500005];

int cnt[500005];

int top=0;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		memset(card,0,sizeof(card));
		memset(nowp,0,sizeof(nowp));
		
		top = 0;
		
		for(int j=i;j<=n;j++){
			if(nowp[a[j]]!=0){
				for(int k=nowp[a[j]]+1;k<=top;k++){
					nowp[card[k]] = 0;
				}
				
				top = nowp[a[j]];
			}
			else{
				top++;
				card[top] = a[j];
				nowp[a[j]] = top;
			}
			
//			cout<<i<<" "<<a[j]<<" "<<j<<"top"<<top<<":";
			
//			for(int k=1;k<=top;k++){
////				cout<<card[k]<<" ";
//			}
			
//			cout<<"\n";
		}
		
//		cout<<"--------------------\n";
		
		for(int j=1;j<=top;j++){
			cnt[card[j]]++;
		}
	}

	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	
	//模拟？
	
	return 0;
}

/*
太棒了是卡的斯 
*/

//
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);


//5000 5000
//25000000
//2.5e7
//tot 36pts
//
