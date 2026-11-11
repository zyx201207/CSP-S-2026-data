#include<bits/stdc++.h>
using namespace std;
bool bo[100000]; 
int cnt[100000];
int n,m;
int xxx=0;
int Max=-1000;
int a[100000];
void search(int k){
	
	for(int i=1;i<=n;i++){
		if(!bo[i]){
			cnt[k]=a[i];
			bo[i]=1;
			search(k+1);
			
		}
	}
		if(k>m){
		bo[k]=0;
			xxx=cnt[1];
		for(int i=1;i<=m;i++){
		xxx=cnt[i]&xxx;
			//cout<<cnt[i]<<" ";
		}
	//	cout<<endl;
		Max=max(Max,xxx);
		return;
	}
	
}
int main()
{
	//ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	search(1);
	cout<<Max;
	return 0;
 } 
 /*
 4 2 
 3 15 12 12 
 */
 /*
  5 3 
 31 3 1 15 7
 */
