#include<bits/stdc++.h>

using namespace std;

int n;
int m;
int a[500000];
int bol[300001];
string pai="";

int main(){
//    freopen("card.in","r",stdin);
//    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<=n;j++){
            if(pai.find(a[j])!=-1){
                while(pai.find(a[j])!=-1){
                    pai.erase(pai.find(a[j]));
                }
            }
            string a=pai;
            pai+=(char)a[j];
            if(a==pai){
                    cout<<"qwertyuiopasdfghjklzxcvbnm"<<"  ";
            }
        }
        for(int j=1;j<=m;j++){
            if(pai.find(j)!=-1){
                bol[j]++;
            }
        }
        cout<<pai<<"\n";
    }
    for(int i=1;i<=m;i++){
        cout<<bol[i];
    }
    cout<<char(a[1]);

 //   fclose(stdin);
 //   fclose(stdout);

    return 0;
}
