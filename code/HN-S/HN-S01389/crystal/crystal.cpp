#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		if(a[i]+1==a[i+1]){
			m--;
			sum++;
			if(a[i+1]+1==a[i+2]){
				if(m>=i+1){
					m-=2;
					sum++;
				}
				else
					break;
				if(a[i+2]+1==a[i+3]){
					if(m>=i+2){
						m-=3;
						sum++;
					}
					else
						break;
					if(a[i+3]+1==a[i+4]){
						if(m>=i+3){
							m-=4;
							sum++;
						}
						else
							break;
						if(a[i+4]+1==a[i+2]){
							if(m>=i+4){
							m-=5;
							sum++;
							}
						else
							break;
						}
						else if(a[i+4]+2==a[i+5]){
							if(m>=i+5){
								m-=6;
								sum++;
							}
							else
								break;
							}
					else if(a[i+3]+2==a[i+4]){
						if(m>=i+2){
							m-=5;
							sum++;
						}
						else
							break;
					}
				else if(a[i+2]+2==a[i+3]){
					if(m>=i+3){
						m-=4;
						sum++;
					}
					else
						break;
			}	
			else if(a[i+1]+2==a[i+2]){
				if(m>=i+2){
					m-=3;
					sum++;
				}
				else
					break;
			}	
		}
	}
	}
		}
		else if(a[i]+2==a[i+1])	{
			if(m>=i+1){
				m-=2;
				sum++;
			}
			else
				break;
		}	
	}
	cout<<sum;
	return 0;
}
