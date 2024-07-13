#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int Size[N];  // size compression
int sz,cm;
void make(int node)
{
 parent[node]=node;
 Size[node]=1;
}
int Find(int n)
{
  if(n==parent[n]) return n;
  else return parent[n]=Find(parent[n]); // path compression

}
void Union(int a,int b)
{
  a=Find(a);  //find root
  b=Find(b);  //find root
  if(a==b)
  {
      //cout<<"friend"<<endl;
  }
  else
  {
      if(Size[a]<Size[b]) swap(a,b);
      parent[b]=a;  //b holo coto tai a ar satha add kore dessi
      Size[a]+=Size[b];
      sz=max(sz,Size[a]);
      cm--;
  }

}

int main()
{
  int node,eg;
  cin>>node>>eg;
  cm=node;
  sz=0;
  for(int i=1;i<=node;i++)
  {
      make(i);
  }
  for(int i=1;i<=eg;i++)
  {
      int a,b;
      cin>>a>>b;
      Union(a,b);
      cout<<cm<<" "<<sz<<endl;
  }
  //cout<<component<<endl;



}

