/************************************************************************/
/**
 * @file swSTDHeaders
 * @author AccelMR
 * @date 2019/02/21
 * @brief Header Include classes
 */
 /************************************************************************/

#pragma once

/************************************************************************/
/*
 * C type objects
 */                                                                     
/************************************************************************/
#include <cmath>
#include <cassert>


/************************************************************************/
/*
 * STL containers
 */                                                                     
/************************************************************************/
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <array>
#include <forward_list>

#include <unordered_map>
#include <unordered_set>

/************************************************************************/
/**
 * STL File stuff
 */                                                                     
/************************************************************************/
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

/*****************************************************************************/
/**
 * STL smart pointers
 */
 /*****************************************************************************/
#include <memory>

/************************************************************************/
/*
 * Threads
 */                                                                     
/************************************************************************/
#include <mutex>
#include <thread>

namespace swEngineSDK{

/* =^..^=   =^..^=   =^..^=    =^..^=    =^..^=    =^..^=    =^..^=   =^..^=  */
/* =^..^=   =^..^=   =^..^=    =^..^=    =^..^=    =^..^=    =^..^=   =^..^=  */
struct EnumClassHash
{
  template<typename T>
  constexpr std::size_t
    operator()(T t) const {
    return static_cast<std::size_t>(t);
  }
};
/* =^..^=   =^..^=   =^..^=    =^..^=    =^..^=    =^..^=    =^..^=   =^..^=  */
/* =^..^=   =^..^=   =^..^=    =^..^=    =^..^=    =^..^=    =^..^=   =^..^=  */

  /************************************************************************/
  /**
   * String STL
   */                                                                     
  /************************************************************************/
  using String = std::string;
  using WString = std::wstring;
  using StringStream = std::stringstream;


  /************************************************************************/
  /**
   * Standard Containers defined as own 
   */                                                                     
  /************************************************************************/

  /**
   * @brief Hasher that handles custom enums automatically.
   */
  template<typename Key>
  using HashType = typename std::conditional<std::is_enum<Key>::value,
    EnumClassHash,
    std::hash<Key>>::type;

  /**
   * @brief Double ended queue. Allows for fast insertion and removal at both
   *        its beginning and end.
   */
  template<typename T, typename A = std::allocator<T>>
  using Deque = std::deque<T, A>;

  /**
  * @brief Dynamically sized array that stores element contiguously.
   */
  template<typename T, typename A = std::allocator<T>>
  using Vector = std::vector<T, A>;

  /**
   * @brief Container that supports constant time insertion and removal, but
   *        without fast random access to elements. Internally implemented as a
   *        doubly linked list. Use ForwardList if you do not need reverse
   *        iteration.
   */
  template<typename T, typename A = std::allocator<T>>
  using List = std::list<T, A>;

  /**
   * @brief Container that supports constant time insertion and removal, but
   *        without fast random access to elements. Internally implemented as a
   *        singly linked list that doesn't support reverse iteration.
   */
  template<typename T, typename A = std::allocator<T>>
  using ForwardList = std::forward_list<T, A>;

  /**
   * @brief First-in, last-out data structure.
   */
  template<typename T, typename A = std::allocator<T>>
  using Stack = std::stack<T, std::deque<T, A>>;

  /**
   * @brief First-in, first-out data structure.
   */
  template<typename T, typename A = std::allocator<T>>
  using Queue = std::queue<T, std::deque<T, A>>;

  /**
   * @brief An associative container containing an ordered set of elements.
   */
  template<typename T, typename P = std::less<T>, typename A = std::allocator<T>>
  using Set = std::set<T, P, A>;

  /**
   * @brief An associative container containing an ordered set of key-value
   *        pairs.
   */
  template<typename K,
    typename V,
    typename P = std::less<K>,
    typename A = std::allocator<std::pair<const K, V>>>
    using Map = std::map<K, V, P, A>;

  /**
   * @brief An associative container containing an ordered set of elements
   *        where multiple elements can have the same key.
   */
  template<typename T, typename P = std::less<T>, typename A = std::allocator<T>>
  using MultiSet = std::multiset<T, P, A>;

  /**
   * @brief An associative container containing an ordered set of key-value
   *        pairs where multiple elements can have the same key.
   */
  template<typename K,
    typename V,
    typename P = std::less<K>,
    typename A = std::allocator<std::pair<const K, V>>>
    using MultiMap = std::multimap<K, V, P, A>;

  /**
   * @brief An associative container containing an unordered set of elements.
   *        Usually faster than Set for larger data sets.
   */
  template<typename T,
    typename H = HashType<T>,
    typename C = std::equal_to<T>,
    typename A = std::allocator<T>>
    using UnorderedSet = std::unordered_set<T, H, C, A>;

  /**
   * @brief An associative container containing an ordered set of key-value
   *        pairs. Usually faster than Map for larger data sets.
   */
  template<typename K,
    typename V,
    typename H = HashType<K>,
    typename C = std::equal_to<K>,
    typename A = std::allocator<std::pair<const K, V>>>
    using UMap = std::unordered_map<K, V, H, C, A>;

  /**
   * @brief An associative container containing an ordered set of key-value
   *        pairs where multiple elements can have the same key. Usually faster
   *        than MultiMap for larger data sets.
   */
  template<typename K,
    typename V,
    typename H = HashType<K>,
    typename C = std::equal_to<K>,
    typename A = std::allocator<std::pair<const K, V>>>
    using UnorderedMultimap = std::unordered_multimap<K, V, H, C, A>;


  /************************************************************************/
  /**
   * Smart pointers
   */                                                                     
  /************************************************************************/

  /**
   * @brief Short call for shared pointer, can be changed
   */
  template <typename T>
  using SPtr = std::shared_ptr<T>;

  /**
   * @brief Smart pointer that retains shared ownership of a project through
   *        a pointer. Reference to the object must be unique. The object is
   *        destroyed automatically when the pointer to the object is destroyed.
   */
  template <typename T,
            typename Deleter = std::default_delete<T>>
    using UPtr = std::unique_ptr<T, Deleter>;

  /**
  * @brief works for make shared pointer 
  */
  using std::make_shared;

  /************************************************************************/
  /*
   * Threads stuff
   */                                                                     
  /************************************************************************/
  
  /** 
   * @brief Short call for mutex
   */
  using Mutex =  std::mutex;

}
