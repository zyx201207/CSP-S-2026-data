#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int cnt[500005];
int ccnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	int x=n;
	int y=0;
	while(x--){
        int wz=0;
        y++;
        for(int i=y;i<=n;i++){
            if(cnt[a[i]]==0){
                wz++;
                b[wz]=a[i];
                cnt[a[i]]++;
            }
            else{
                for(int j=1;j<=wz;j++){
                    if(b[wz]=a[j]){
                        for(int k=j+1;k<=wz;k++){
                            if(cnt[b[k]]>0){
                                cnt[b[k]]--;
                            }
                            b[k]=0;
                        }
                        wz=j;
                        break;
                    }
                }
            }
        }
        for(int l=1;l<=wz;l++){
            ccnt[b[l]]++;
        }
        for(int i=1;i<=wz;i++){
            b[wz]=0;
        }
        for(int i=1;i<=m;i++){
            cnt[i]=0;
        }
	}
	for(int i=1;i<=m;i++){
        cout<<ccnt[i]<<" ";
	}
	return 0;
}
