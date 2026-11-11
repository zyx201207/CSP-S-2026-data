#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],test1maxv,test2maxv,test3all;bool test4temp[25],test5=1,test6=1;
int dfs(int sum,int ans){
	if(sum==m){
		return ans;
	}
	int maxv=0;
	for(int i=1;i<=n;i++){
		if(test4temp[i]==0){
			test4temp[i]=1;
			if(sum==0){
				maxv=max(maxv,dfs(1,a[i]));
			}else{
				maxv=max(maxv,dfs(sum+1,(ans&a[i])));
			}
			test4temp[i]=0;
		}
	}
	return maxv;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		test1maxv=max(test1maxv,a[i]);
		if(log2(a[i]+1)!=int(log2(a[i]+1))){
			test5=0;
		}
		if(a[i]>4){
			test6=0;
		} 
	}
	if(m==1){
		cout<<test1maxv;
		return 0;
	}else if(m==2){
		for(int i=1;i<=2000;i++){
			for(int j=i+1;j<=2000;j++){
				test2maxv=max(test2maxv,(a[i]&a[j]));
			}
		}
		cout<<test2maxv;
		return 0;
	}else if(m==n){
		test3all=a[1];
		for(int i=2;i<=n;i++){
			test3all=(test3all&a[i]);
		}
		cout<<test3all;
		return 0;
	}else if(n<=20){
		cout<<dfs(0,0);
		return 0;
	}else if(test5){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}else if(test6){
		int sum1=0,sum2=0,sum3=0,sum4=0,sum0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==4){
				sum4++;
			}else if(a[i]==3){
				sum3++;
			}else if(a[i]==2){
				sum2++;
			}else if(a[i]==1){
				sum1++;
			}else{
				sum0++;
			}
		}
		if(sum4>=m){
			cout<<4;
		}else if(sum3>=m){
			cout<<3;
		}else if(sum2>=m){
			cout<<2;
		}else if(sum1>=m){
			cout<<1;
		}else if(sum0>=m){
			cout<<0;
		}else if(sum4<m){
			if(sum3 && sum2 && (sum3+sum2)>=m){
				cout<<2;
			}else if(sum2 && sum1 && (sum2+sum1)>=m){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(sum3<m){
			if(sum3 && sum2 && (sum3+sum2)>=m){
				cout<<2;
			}else if(sum2 && sum1 && (sum2+sum1)>=m){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(sum2<m){
			if(sum3 && sum2 && (sum3+sum2)>=m){
				cout<<2;
			}else if(sum2 && sum1 && (sum2+sum1)>=m){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(sum1<m){
			if(sum3 && sum2 && (sum3+sum2)>=m){
				cout<<2;
			}else if(sum2 && sum1 && (sum2+sum1)>=m){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			if(sum3 && sum2 && (sum3+sum2)>=m){
				cout<<2;
			}else if(sum2 && sum1 && (sum2+sum1)>=m){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<dfs(0,0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
