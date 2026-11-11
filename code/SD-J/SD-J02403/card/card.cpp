#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n;
	cin>>n;
	int m;
	cin>>m;
	int a[100000];
	int ans[10000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int zhuomian[10000]={};
		int paishu=0;
		for(int j=i;j<=n;j++){
			for(int x=1;x<=paishu;x++){
				if(zhuomian[x]==a[j]){
					int qcshu=0;
					for(int qc=x;qc<=paishu;qc++){
						zhuomian[qc]=0;
						qcshu++;
					}
					paishu-=qcshu;
				}
			}
			zhuomian[paishu+1]=a[j];
			paishu++;
		}
		/*cout<<paishu<<" ";
		cout<<endl;*/
		for(int j=1;j<=paishu;j++)
		if(zhuomian[j])
		ans[zhuomian[j]]++;
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
 } 
 
 /*
10 3 
3 1 2 1 3 2 3 1 2 1
 */
