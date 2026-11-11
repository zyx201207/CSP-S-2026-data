#include<bits/stdc++.h>
using namespace std;
//余俊辰 SN-J01113 西安市曲江第一学校 
const int M=3e5+10;
const int N=5e5+10;
int a[N],b[N],num[M],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	int tongji[M];
	for(int time=1;time<=n;time++){
		for(int i=1;i<=n;i++)a[i]=b[i],num[a[i]]=0;
		for(int i=0;i<time;i++)a[i]=0;//初始化 
		
		for(int i=time;i<=n;i++){
			int p;
			num[a[i]]++; 
			if(a[i]!=0 && num[a[i]]>1)//第i张牌重复了
			{
				for(int k=time;k<i;k++){
				
					if(a[k]==a[i]){
						p=k;break;
					}
				}//上一张重复的位置 
				for(int j=p;j<i;j++)num[a[j]]=0,a[j]=0;//收牌 
				num[a[i]]=1;
			}
			
		}
	/*	cout<<"DEBUG:";
		for(int i=time;i<=n;i++)cout<<a[i]<<" ";
		cout<<endl;*/
		for(int i=time;i<=n;i++)if(a[i]!=0)tongji[a[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<tongji[i]<<" ";
	return 0;
}

