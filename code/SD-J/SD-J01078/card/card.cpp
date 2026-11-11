#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		for(int j=1;j<i-1;j++){
			if(a[j]<a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	//二进制转化
	int two;
	string st_two[n];
	for(int i=0;i<n;i++){
		two=1;
		//8421码 
		while(two<a[i]){
			two*=2;
		}
		int j=0,d=0;
		while(d>=0){
			int d=two/2;	
			if(a[i]-d>=0){
				a[i]-=d;
				st_two[i]+='1';
			}else{
				st_two[i]+='0';
			}
		}
	}
	//判断相同数
	//补位，先找出最多位（st[0]） 
	int MAX=st_two[0].size();
	//记住补位数量 
	int b[n];
	for(int i=0;i<n;i++){
		b[i]=MAX-st_two[0].size();
	}
	string temp[n];
	for(int i=0;i<n;i++){
		for(int j=st_two[i].size();j<b[i];j++){
			st_two[i][j]+='0';
			
		}
		temp[i]+=st_two[i];
		for(int j=MAX-1;j>=0;j--){
			st_two[i][MAX-j-1]=temp[i][j];
		}
	}
	
	int s[n],s2[n],ma[m],s1;
	//统计1 
	//j行，i列 
	for(int j=0;j<MAX;j++){
		for(int i=0;i<n;i++){
			s1+=st_two[i][j];
		}
		if(s1>=m){
			for(int i=0;i<n;i++){
				if(st_two[i][j]=='1'){
					s[i]++;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		s2[i]=s[i];
	} 
	for(int i=0;i<n;i++){
		for(int j=1;j<i-1;j++){
			if(a[j]<a[j+1]){
				int temp=s[j];
				s[j]=a[j+1];
				s[j+1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[j]==s2[i]){
				ma[i]=i;
			}
		}
	}
	//计算
	int x=0;
	for(int i=0;i<MAX;i++){
		for(int j=0;j<m-1;j++){
			if(st_two[ma[j]][i]==1&&st_two[ma[j+1]][i]==1){
				x+=1;
			}else{
				st_two[ma[j+1]][i]=0;
			}
		}	
	} 
	cout<<x;
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
