/*
The zlib/libpng License

Copyright (c) 2009-2010 Martin Preisler

This software is provided 'as-is', without any express or implied warranty. In no event will
the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial 
applications, and to alter it and redistribute it freely, subject to the following
restrictions:

    1. The origin of this software must not be misrepresented; you must not claim that 
		you wrote the original software. If you use this software in a product, 
		an acknowledgment in the product documentation would be appreciated but is 
		not required.

    2. Altered source versions must be plainly marked as such, and must not be 
		misrepresented as being the original software.

    3. This notice may not be removed or altered from any source distribution.
*/

#ifndef __OISB_SEQUENCE_ACTION_H__
#define __OISB_SEQUENCE_ACTION_H__

#include "OISBGlobal.h"
#include "OISBAction.h"

namespace OISB
{
	/**
	 * @brief states have to be activated in sequence to activate this action
	 */
	class _OISBExport SequenceAction : public Action
	{
		public:
			/**
			 * @brief constructor
			 * 
			 * @param parent parent action schema
			 * @param name name / identifier
			 */
			SequenceAction(ActionSchema* parent, const String& name);
			
			/**
			 * @brief destructor
			 */
			virtual ~SequenceAction();

            /// @copydoc Action::getActionType
            virtual ActionType getActionType() const;

            /// @copydoc Action::createBinding
            virtual Binding* createBinding();

            /// @copydoc Action::destroyBinding
            virtual void destroyBinding(Binding* binding);

        protected:
            /// @copydoc Action::impl_process
            virtual bool impl_process(Real delta);

            /// if true, even when you press a wrong key, the sequence works if you press the right one in the timeout
            //bool mAllowWrongStates; //< note: Only states that are bound are checked!
            /// timeout between states (defaults to 1 second)
            Real mTimeout;

            struct BindingState
            {
                Real timeout;
                size_t position;
            };

            typedef std::vector<BindingState> BindingStateList;
            /// internal binding states
            BindingStateList mBindingStates;
	};
}

#endif
