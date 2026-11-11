#include<bits/stdc++.h>
using namespace std;
long long a;
string two[200010]; 
int tong[100];
int suo=1;
int thrown;
int digit;
int temp;
bool cmp(string a,string b){
	return a[digit]>b[digit];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ans=0;
	string filling="0000000000000000000000000000000000000000";
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		suo=0;
		while(a){
			tong[suo]+=(a&1);
			suo++;
			two[i].push_back((a&1)+48);
			a/=2;
//			cout<<a<<"\n";
		}
		
	}
	for(int i=1;i<=n;i++) two[i]+=filling;
	thrown=n;
//	for(int i=1;i<=n;i++) {
//		reverse(two[i].begin(),two[i].end());
//		cout<<two[i]<<"\n";
//	}
//	for(int i=0;i<=30;i++){
//		cout<<tong[i]<<" ";
//	}
	
//	cout<<endl;
	for(int i=30;i>=0;i--){ //2的次方 
		digit=i;
//		cout<<digit<<" "<<thrown<<" "<<tong[digit]<<"\n";
		if(tong[digit]>=m){
			ans+=1LL<<digit;
//			cout<<"开始贡献\n";
			sort(two+1,two+1+thrown,cmp);
			temp=thrown;
			
			for(int j=1;j<=thrown;j++){
				if(two[j][digit]=='0'){ //这一个不会选,把他的位贡献减去
//					cout<<two[j]<<" ";
//					cout<<j<<"去掉此，剪掉\n";
				 	temp=min(temp,j-1);
				 	if(digit!=0){
						for(int k=digit-1;k>=0;k--){
							if(two[j][k]!='0'){
								tong[k]--;
							}
						}				 		
					 }
				}
			}
			thrown=temp;
		} 		
	} 
	cout<<ans;
	return 0;
}

/*
6
3
435
435
67 34 57 34
110011011
110011011
100111
010001
010001



1100001




*/
