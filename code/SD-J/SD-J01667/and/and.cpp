#include<iostream>
#include<algorithm>
using namespace std;
int n,m,num[200005],the_biggest;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>num[i];
	if(n==m){
		the_biggest=num[0];
		for(int i=0;i<n;i++) the_biggest&=num[i];
		cout<<the_biggest;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if(m==1){
		sort(num,num+n);
		cout<<num[n-1];
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				if(num[i]&num[j]>the_biggest) the_biggest=num[i]&num[j];
			}
		}
		cout<<the_biggest;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if(m==n-1){
		int linshi[200005]={};
		for(int i=0;i<n;i++){
			int aaa;
			if(i!=0) aaa=num[0];
			else aaa=num[1];
			for(int j=0;j<n;j++){
				if(j==i) continue;
				aaa&=num[j];
			}
			linshi[i]=aaa;
		}
		sort(linshi,linshi+n);
		cout<<linshi[n-1];
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
}
