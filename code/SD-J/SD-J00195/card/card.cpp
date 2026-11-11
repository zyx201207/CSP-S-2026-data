#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;
int search(vector <int> nums,int op,int k){
    auto it=lower_bound(nums.begin(),nums.end(),op);
    if((nums[it-nums.begin()]==op)&&(it-nums.begin()<k)) return it-nums.begin();
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    int n,m;
    cin>>n>>m;
    vector <int> a(n);
    int k=0;
    for(int i=0;i<n;i++) cin>>a[i];
    vector <int> ans(m,0);
    for(int games=0;games<n;games++){
        vector <int> num(n,0);
        vector <bool> as(m,false);
        k=games;
        for(int i=games;i<n;i++){
            int nown=search(num,a[i],k);
            if(nown==-1){
                num[k++]=a[i];
            }else{
                k=nown+1;
            }
        }
        for(int i=games;i<k;i++){
            as[num[i]]=true;
        }
        for(int i=0;i<m;i++){
            if(as[i]) ans[i]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<' ';
    }
    */
    int n,m;
    cin>>n>>m;
    vector <int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cout<<n<<' ';
    return 0;
}
/*
    int n,m;
    cin>>n>>m;
    vector <int> a(n);
    int k=0;
    for(int i=0;i<n;i++) cin>>a[i];
    vector <int> ans(m,0);
    for(int games=0;games<n;games++){
        vector <int> num(n,0);
        num=a;
        vector <bool> as(m,false);
        for(int l=0,r=n-1;l<r&&l<num.size();l++,r=num.size()-1){
        	while(a[l]!=a[r]&&l<r) r--;
        	if(a[l]==a[r]){
        		num.erase(num.begin()+l,num.begin()+r-1);
			}
		}
        for(int i=0;i<num.size();i++){
            as[num[i]]=true;
        }
        for(int i=0;i<m;i++){
            if(as[i]) ans[i]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<' ';
    }
*/
