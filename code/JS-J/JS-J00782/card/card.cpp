#include<bits/stdc++.h>
using namespace std;
vector<int>a;
vector<int>b(300005,0);
vector<bool>book(300005,0);
stack<int>c;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cc;
    for(int i=0;i<n;i++){
        cin>>cc;
        a.push_back(cc);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            //cout<<"throw: "<<a[j]<<endl;
            if(book[a[j]]==1){
                //cout<<"catch: ";
                while(!c.empty()){
                    if(c.top()==a[j])break;
                    //cout<<c.top()<<" ";
                    book[c.top()]=0;
                    c.pop();
                }
                if(!c.empty()){
                    //cout<<c.top()<<" ";
                    c.pop();
                }
                //cout<<endl;
                c.push(a[j]);
            }
            else{
                c.push(a[j]);
                book[a[j]]=1;
            }
        }
        fill(book.begin(),book.end(),0);
        for(int k=0;k<=c.size();k++){
            if(!c.empty()){
                b[c.top()]++;
                //cout<<c.top()<<' '<<i<<'\n';
                c.pop();
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
