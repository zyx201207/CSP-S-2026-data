//小 R 有 n 颗能量水晶，其中第 i (1 ≤ i ≤ n) 颗的能量值为整数 ai。小 R 想用其中若干颗能量水晶合成一颗大水晶，用于合成的水晶必须具有相同的能量值。小 R 希望参与合成的水晶尽可能多。他可以进行至. 多. m 次操作。每次操作可以任选一颗水晶，将其能量值增加 1；同一颗水晶可以被重复选择。你需要帮助小 R 求出，进行至多 m 次操作后，他最多能用多少颗能量水晶合成一颗大水晶。
#include<bits/stdc++.h>
using namespace std;
int n,a[100005],m,sum=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;++i){
    	for(int j=1;j<=n;++j){
		    if(a[i]<a[j]){
			    swap(a[i],a[j]);
			}
			
		}
		
	}
	cin>>m;
    for(int i=1;i<=n;++i){
	    a[i]++;
		m--;
		for(int j=1;j<=n;++j){
			a[i]++;
			m--;
			if(a[i]==a[i+1]){
				sum++;
			}
			if(i-j>0&&a[i]!=a[i-j]){
               	for(int i=1;i<=i-j;++i){
               		a[i-j]++;
					m--;
					if(a[i]==a[i-j]){
						
						continue;
					}
					if(m==0){
						break;
					}
				}
			}
		}
			if(m==0){
				break;
			}
	}
	
	cout<<sum;
}



